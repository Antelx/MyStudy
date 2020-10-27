from .utils import switch


@switch
def add(x, y, **kwargs):
    print(x + y)


@switch
def hello(config):
    print('hello')
