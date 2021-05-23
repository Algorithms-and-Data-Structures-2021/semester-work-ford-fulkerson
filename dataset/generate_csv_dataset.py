import argparse
import random

DEFAULT_DESCRIPTION = 'CSV dataset generator script demo.'
DEFAULT_SAMPLES = 100


def parse_args():
    """
    Парсинг аргументов командной строки (CLI).
    :return интерфейс для работы с аргументами.

    Больше информации на https://docs.python.org/3.7/howto/argparse.html
    """
    parser = argparse.ArgumentParser(description=DEFAULT_DESCRIPTION)

    parser.add_argument('output',
                        type=str,
                        help='output CSV file, e.g. data/output.csv')

    parser.add_argument('--size',
                        type=int,
                        default=DEFAULT_SAMPLES,
                        help='number of size to generate (default: {})'.format(DEFAULT_SAMPLES))

    return parser.parse_args()


if __name__ == '__main__':
    # args = parse_args()
    size = int(input('Adjacency matrix size:\n'))

    # валидация аргументов
    if size < 0:
        raise ValueError('Number of size must be greater than 0.')

    path = input("Path to file to save:\n")

    # запись данных в файл
    with open(path, 'a') as file:
        for i in range(size):
            for j in range(size - 1):
                ph = random.randint(1, 10)
                file.write('{},'.format(ph))
            ph = random.randint(1, 10)
            file.write('{}\n'.format(ph))
