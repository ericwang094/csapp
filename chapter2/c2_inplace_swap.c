//
// Created by yongqi wang on 14/7/2025.
//

void inplac_swap(int *x, int *y) {
	*y = *x ^ *y;
    *x = *x ^ *y;
    *y = *x ^ *y;
}