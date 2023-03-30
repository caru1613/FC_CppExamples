export module swap;

export void swap(int&x, int&y)  // ³ëÃâ½ÃÅ³ °Í¿¡¸¸ export¸¦ ±âÀÔ
{
	int temp = x;
	x = y;
	y = temp;
}
