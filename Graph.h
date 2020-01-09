namespace Graph{
	int map(float val, int min, int max, float new_min, float new_max) {
		float div = (float)(max - min);
		float new_div = new_max - new_min;
		return (int)(val*(new_div / div));
	}
}