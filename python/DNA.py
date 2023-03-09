import csv
from typing import Dict, List

# Esta funcion lee el CSV y devuelve 2 elementos, una lista de "STRs"
# y una lista de perfiles, luego usa `DictReader` para leer la CSV
# luego extrae los datos en el formato deseado


def read_csv(file: str) -> Dict[str, List[Dict[str, str]]]:
    with open(file, mode="r") as f:
        reader = csv.DictReader(f)
        STRs = reader.fieldnames[1:]
        profiles = list(reader)
    return {'STRs': STRs, 'profiles': profiles}
# Esta funcion toma la secuencia DNA y el STR como input,luego devuelve el
# maximo numero consecutivo de repeticiones STR en la secuencia
# itera sobre la secuencia y confirma los match en STR, continua siguiendo
# el numero maximo de repeticiones consecuticas y las devuelve al final


def find_repeats(sequence: str, STR: str) -> int:
    L = len(STR)
    max_repeats = 0
    for i in range(len(sequence)):
        repeats = 0
        if sequence[i: i + L] == STR:
            repeats += 1
            while sequence[i: i + L] == sequence[i + L: i + (2 * L)]:
                repeats += 1
                i += L
        if repeats > max_repeats:
            max_repeats = repeats
    return max_repeats
# esta es la funcion principal y toma como input los PATHS de la base de datos
# ejecuta las 2 funciones de arriba, itera sobre los perfiles y confima y
# verifica el conteo de STRsen la secuencia que coincide con el conteo STRs en
# el perfil, si hay un match imprime el nombre del perfil y devuelve o,
# caso contrario devuelve "NO MATCH" e imprime 1


def main(database: str, sequence: str):
    data = read_csv(database)
    STRs = data['STRs']
    profiles = data['profiles']
    seq_str_count = dict.fromkeys(STRs, 0)
    with open(sequence, mode="r") as f:
        sequence = f.readline()
    for STR in STRs:
        seq_str_count[STR] = find_repeats(sequence, STR)
    for profile in profiles:
        match_count = 0
        for STR in STRs:
            if int(profile[STR]) != seq_str_count[STR]:
                continue
            match_count += 1
        if match_count == len(STRs):
            print(profile['name'])
            return 0
    print("No match")
    return 1
    
if __name__ == "__main__":
    import sys
    if len(sys.argv) != 3:
        print("Usage: python dna.py data.csv sequence.txt")
        sys.exit(1)
    sys.exit(main(sys.argv[1], sys.argv[2]))