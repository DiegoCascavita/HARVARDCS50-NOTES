from cs50  import get_string


def dictionary(text):
    # cuenta el numero de letras usando comprehension
    letter_count = sum(c.isalpha() for c in text)
    # cuenta el numero de palabras usando el metodo .split
    word_count = len(text.split())
    # cuenta el numero de sentencias usando el operador "in"
    sentence_count = sum(c in ".!?" for c in text)
    # calcula el promedio de letras cada 100 palabras
    l = 100 * letter_count / word_count
    # calcula el promedio de sentencias cada 100 letras
    s = 100 * sentence_count / word_count
    #  calcula el Coleman-Liau index usando esta formula
    result = (0.0588 * l) - (0.296 * s) - 15.8
    #redondea el resultado al numero entero mas cercano
    return round(result)


text = get_string("Text: ")
index = dictionary(text)
# imprime el texto de acuerdo al grado
if index < 1:
    print("Before Grade 1")
elif index > 16:
    print("Grade 16+")
else:
    print(("Grade {}").format(index))