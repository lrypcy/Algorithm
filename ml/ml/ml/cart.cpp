#include "cart.h"

template <typename T>
T Cart<T>::calMetric(const std::vector<std::vector<T> > & data, const std::vector<uint>& sorted_idx, const std::vector<uint> fea_idx) {
	
}

template<typename T>
std::pair<T,T> Cart<T>::findBestSplit(const std::vector<std::vector<T> > & data, uint fea_idx) {
	//int j, s;	
	T s;
	T min_gini;
	for ();// transverse all split variable
		cur_gini=calGini();//calculate corresponding gini index.
		if(cur_gini < min_gini)
			s=, min_gini=;
	std::pair<T, T> res;
	res.first = s, res.second = min_gini;
}

template<typename T>
std::vector<uint> Cart<T>::sortBasedOnFea(uint fea_idx) {
	std::vector<uint> sorted_idx(sample_data.size());
	for (uint i = 0; i < sample_data.size(); ++i)
		sorted_idx[i] = i;
	sort(sorted_idx.begin(), sorted_idx.end(), [](uint a, uint b) {sample_data[a][feature_idx] < sample_data[b][feature_idx]; });
	return sorted_idx;
}


template <typename T>
std::vector<T> Cart<T>::predict(const std::vector<std::vector<T> >& features) {
	std::vector<T> res(features.size());
	for (uint i = 0; i < features.size(); ++i) {
		auto cur_node = Cart<T>::root;
		while (!cur_node->is_leaf) {
			uint cur_idx = cur_node->feature->idx;
			if (features[cur_idx] <= cur_node->value)
				cur_node = cur_node->left;
			else
				cur_node = cur_node->right;
		}
		res[i] = cur_node->value;
	}
	return res;
}

