--1 SQL
SELECT name FROM songs;
--2 SQL
SELECT name FROM songs ORDER BY tempo;
--3 SQL
SELECT name FROM songs ORDER BY duration_ms DESC LIMIT 5;
--4 SQL
SELECT name FROM songs WHERE danceability > 0.75 AND energy > 0.75 AND valence > 0.75;
--5 SQL
SELECT avg(energy) FROM songs;
--6 SQL
SELECT songs.name FROM songs
JOIN artists ON songs.artist_id = artists.id
WHERE artists.name = "Post Malone";
--7 SQL
SELECT AVG(songs.energy) FROM songs
JOIN artists ON songs.artist_id = artists.id
WHERE artists.name = "Drake";
--8 SQL
SELECT name FROM songs
WHERE name LIKE '%feat.%';
