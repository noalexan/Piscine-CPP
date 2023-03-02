#pragma once

template <typename T>
void iter(T *tab, int size, void (&f)(T&)) {
	for (int i = 0; i < size; i++) {
		f(tab[i]);
	}
}
