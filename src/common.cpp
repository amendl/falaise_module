
#include<common.h>

int my_simple_argmax(std::vector<float> &data) {
	float max = -1000.;
	int max_index = 0;
	for (size_t i =0;i<data.size();i++) {
		if (data[i]>max) {
			max = data[i];
			max_index = i;
		}
		
	}
	return max_index;
}
