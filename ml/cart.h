#ifndef CART_H
#define CART_H
#include <cmath>
#include <vector>
#include <utility>

using uint = unsigned int;

template<typename T>
struct BSTNode {
	uint feature_idx;
	BSTNode<T> * left, *right;
	bool is_leaf;
	T value;
};
template<typename T>
class Cart {

	T calMetric(const std::vector<std::vector<T> > & data,const std::vector<uint>& sorted_idx,const std::vector<uint> fea_idx);

	std::pair<T, T> findBestSplit(const std::vector<std::vector<T> > & data,uint fea_idx);

	std::vector<uint> sortBasedOnFea(uint fea_idx);

	int read();

	train();

	std::vector<T> predict(const std::vector<std::vector<T> >& features);
	
	~Cart();
private:
	std::vector<std::vector<T> > sample_data;
	BSTNode<T>* root;
};

#endif // !CART_H
