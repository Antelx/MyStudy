from .utils import switch


@switch()
def add(x, y, **kwargs):
    print(x + y)


@switch(key='what', return_value='hi')
def hello(config):
    print('hello')
