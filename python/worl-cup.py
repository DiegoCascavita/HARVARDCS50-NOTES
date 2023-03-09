import csv
import sys
import random

# Esta funcion lee los equipos de cada arcivo, y simula un torneo,
# luego imprime la posibilidad de ganar de cada equipo


def main():
    if len(sys.argv) != 2:
        sys.exit("Usage: python tournament.py FILENAME")

    teams = read_teams_from_file(sys.argv[1])
    counts = simulate_tournaments(teams)
    print_chances_of_winning(counts, teams)

    # Esta funcion lee los equipos de la CSV file y devuelve una lista de
    # diccionarios, cada diccionario representa un equipo con las KEYS
    # 'team' y 'rating'


def read_teams_from_file(filename):
    teams = []
    with open(filename) as csvfile:
        reader = csv.DictReader(csvfile)
        for row in reader:
            team = row
            team["rating"] = int(team["rating"])
            teams.append(team)
    return teams

    # simula N torneos usando una lista dada de equipos, devuelve un diccionario
    # donde las KEYS son el nombre del team y los valores son los numeros de
    # victorias


def simulate_tournaments(teams, N=1000):
    counts = {}
    for simulation in range(N):
        winner = simulate_tournament(teams)
        counts[winner] = counts.get(winner, 0) + 1
    return counts

    # imprime el chance de ganar de cada equipo, sorteado por el numero de victorias


def print_chances_of_winning(counts, teams, N=1000):
    for team in sorted(counts, key=lambda team: counts[team], reverse=True):
        print(f"{team}: {counts[team] * 100 / N:.1f}% chance of winning")

    # simula una ronda de torneo con la lista dada de equipos
    # devuelve la lista de equipos que ganaron la ronda


def simulate_game(team1, team2):
    rating_diff = team2["rating"] - team1["rating"]
    probability = 1 / (1 + 10 ** (rating_diff / 600))
    return random.random() < probability

    # simula un torneo con la lista dada de equipos
    # devuelve el equipo que gano el torneo


def simulate_round(teams):
    return [team1 if simulate_game(team1, team2) else team2 for team1,
            team2 in zip(teams[::2], teams[1::2])]


def simulate_tournament(teams):
    if len(teams) < 2:
        return teams[0]["team"]
    return simulate_tournament(simulate_round(teams))


if __name__ == "__main__":
    main()