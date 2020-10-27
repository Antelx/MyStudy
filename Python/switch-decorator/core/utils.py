from functools import wraps


def switch(f):
    @wraps(f)
    def decorated(*args, **kwargs):
        if kwargs['config'].getboolean('switch', f.__name__):
            return f(*args, **kwargs)
        return "Function will not run"

    return decorated
