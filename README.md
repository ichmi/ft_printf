# ft_printf | 42sp

## Introduction
The `printf` is likely one of the most popular commands people see when learning a new programming language. They are easy to understand and very powerful as well.
This is why learning to implement our own version of `printf` can help us better understand what happens internally when entering a `printf("%s", "Hello World\n");`.

## Capabilities
My version of the `printf` function will handle the following specifiers: `cspdiuxX%`
It will also work with these flags: `-0.# +’` (Yes, one of them is a space), and it will handle any possible combination.

## Usage
In order to use it, we should just clone the repo and use `make`:
```bash
git clone https://github.com/ichmi/ft_printf.git
make
```
It is going to generate an archive `libftprintf.a` where you can use in your programs:
```bash
clang main.c libftprintf.a
```

## Limitations
There are a few limitations to consider:
- It doesnt have buffer management, unlike the real `printf`;
- This implementation of `printf` isn't nearly as powerful as the real `prinft` since many features are not included;
- This `ft_printf` relies on my own library `libft`, which makes it slower in performance when compared to the original one;

## Summary
The key to a successful ft_printf (And any project) is a well-structured and extensible code. But I was really happy thinking and working on it while implementing my 
own `printf` function. And I actually added this `ft_printf` project to the `libft` so I can use it in my school C projects.
