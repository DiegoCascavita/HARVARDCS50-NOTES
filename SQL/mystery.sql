-- Keep a log of any SQL queries you execute as you solve the mystery.

-- verificando los crimenes cometidos en el area el 07-28-2021
SELECT description
FROM crime_scene_reports
WHERE date = '2021-07-28' AND street = 'Humphrey Street';

-- solicitando las entrevistas de esa fecha
SELECT name, transcript
FROM interviews
WHERE date = '2021-07-28';

--se encuentran reportes con el nombre de EUGENE, se verifica que no hayan homonimos
SELECT name
FROM people
WHERE name = 'Eugene';

--se encuentran 3 testigos en la entrevita de julio 28 de 2021(EUGENE, RAYMOND Y  RUTH)
SELECT name, transcript
FROM interviews
WHERE year = 2021 AND month = 7 AND day = 28
AND transcript LIKE '%bakery%'
ORDER BY name;

--EUGENE menciona que el criminal retiro dinero, por lo que verificamos las
--transacciones de ese dia
SELECT account_number, amount
FROM atm_transactions
WHERE year = 2021 AND month = 7 AND day = 28
AND atm_location = 'Leggett Street' AND transaction_type = 'withdraw';

-- buscamos los nombres asociados a el numero de cuenta respectiva
SELECT name, amount
FROM people
JOIN bank_accounts ON people.id = bank_accounts.person_id
JOIN atm_transactions ON bank_accounts.account_number = atm_transactions.account_number
WHERE atm_transactions.year = 2021
AND atm_transactions.month = 7
AND atm_transactions.day = 28
AND atm_transactions.atm_location = 'Leggett Street'
AND atm_transactions.transaction_type = 'withdraw'
ORDER BY name;

-- RAYMOND menciona que el criminal hiba a comprar un vuelo
SELECT abbreviation, full_name, city
  FROM airports
 WHERE city = 'Fiftyville';

-- buscando los vuelos del 29 de julio saliendo de Fiftyville
SELECT id, full_name, city, hour, minute
FROM flights
JOIN airports ON flights.destination_airport_id = airports.id
WHERE origin_airport_id = (SELECT id FROM airports WHERE city = 'Fiftyville')
AND year = 2021 AND month = 7 AND day = 29
ORDER BY hour, minute;

--
SELECT flight_id, name, passport_number, seat
FROM passengers
JOIN people ON people.passport_number = passengers.passport_number
JOIN flights ON passengers.flight_id = flights.id
WHERE year = 2021 AND month = 7 AND day = 29
AND hour = 8 AND minute = 20
ORDER BY passport_number;

--buscando las grabaciones de llamadas para encontrar el criminal
SELECT name, duration
FROM phone_calls
JOIN people ON phone_calls.caller = people.phone_number
WHERE year = 2021 AND month = 7 AND day = 28
AND duration <= 60
ORDER BY duration;

--RUTH dice que manejo el carro cerca del sospechoso por lo que se pide
--licencias y placas de los sospechosos
SELECT name, hour, minute
FROM bakery_security_logs
JOIN people ON bakery_security_logs.license_plate = people.license_plate
WHERE year = 2021 AND month = 7 AND day = 28
AND activity = 'exit' AND hour = 10
AND minute >= 15 AND minute <= 25
ORDER BY minute;