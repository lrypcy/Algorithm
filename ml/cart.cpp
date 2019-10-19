#include "cart.h"

template <typename T>
T Cart<T>::calMetric(const std::vector<std::vector<T> > & data, const std::vector<uint>& sorted_idx, uint fea_idx) {
	T total_sum=0;
	for(uint i=0;i<data.size();++i) total_sum+=data[data[i].size()-1];
	// calculate the mean value for each region first and then calculate the mean square error for each part.
	#define eps 1e-10
	cur_sum=0;
	for(uint i=0;i<sorted_idx.size()-1;++i){
		while(
			abs(data[sorted_idx[i]][fea_idx]-
			data[sorted_idx[i+1]][fea_idx])<eps
		) {
			++i;
			cur_sum+=data[sorted_idx[i]][data[0].size()-1];
		}

	}

}

template<typename T>
std::pair<T,T> Cart<T>::findBestSplit(const std::vector<std::vector<T> > & data, uint fea_idx) {
	//int j, s;	
	T s;
	T min_gini;
	for ();// transverse all split variable
		cur_gini=this->calMetric();//calculate corresponding gini index.
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

