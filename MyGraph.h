#pragma once

namespace Graph{
	int map(float val, int min, int max, float new_min, float new_max) {
		if (val <= min) {
			val = 5;
		}
		else if (max <= val) {
			val = max - 5;
		}
		float div = (float)(max - min);
		float new_div = new_max - new_min;
		return (int)(val*(new_div / div));
	}
}