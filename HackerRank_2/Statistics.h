#pragma once

#include <vector>

using namespace std;
class Statistics
{
public:
	Statistics();
	~Statistics();

	void MeanMedianMode();
	void WeightedMean();
	void Quartiles();
	void InterQuartileRange();
	void StandardDeviation();
	void BinomialDistributionI();
	void BinomialDistributionII();
	void GeometricDistributionI();
	void GeometricDistributionII();
	void PoissonDistributionI();
	void PoissonDistributionII();
	void NormalDistributionI();
	void NormalDistributionII();

private:
	float mean(vector<int>& v);
	float median(vector<int>& v);
	float mode(vector<int>& v);
	float weighted_mean(vector<int>& theData, vector<int>& theWeights);
	float standard_dev(vector<int>& v);
	float poisson(float lamda, int k);
	double cumulativeProb(double mean, double stdev, double theValue);

};
