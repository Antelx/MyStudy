from functools import wraps


#
# def switch(f):
#     @wraps(f)
#     def decorated(*args, **kwargs):
#         if kwargs['config'].getboolean('switch', f.__name__):
#             return f(*args, **kwargs)
#         return "Function will not run"
#
#     return decorated

def switch(key=None, return_value=None):
    '''

    :param key: 指定开关的key
    :param return_value: 制定开关关闭后返回的值
    :return: function
    '''

    def decorator(f):
        @wraps(f)
        def decorated(*args, **kwargs):
            if kwargs['config'].getboolean('switch', key if key else f.__name__):
                return f(*args, **kwargs)
            if return_value:
                return return_value
            return "Function will not run"

        return decorated

    return decorator
