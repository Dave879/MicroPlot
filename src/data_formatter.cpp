#include "data_formatter.h"

DataFormatter::DataFormatter() : graph_index_(0)
{
}

std::string DataFormatter::AddBarGraph(std::string name)
{
	CleanStreamAndIncrementIndex(graph_index_);
	tmp_ss_ << "nb>" << name;
	return tmp_ss_.str();
}

std::string DataFormatter::AddStringLog(color c)
{
	tmp_ss_.str("");
	tmp_ss_ << "0000s>" << c;
	return tmp_ss_.str();
}

std::string DataFormatter::AddStringLog()
{
	tmp_ss_.str("");
	tmp_ss_ << "0000s>";
	return tmp_ss_.str();
}

std::string DataFormatter::AddLineGraph(std::string name)
{
	CleanStreamAndIncrementIndex(graph_index_);
	tmp_ss_ << "nl>" << name;
	return tmp_ss_.str();
}

std::string DataFormatter::AddLineGraph(std::string name, int64_t min, int64_t max)
{
	CleanStreamAndIncrementIndex(graph_index_);
	tmp_ss_ << "nl" << INT64_TO_HEX << min << INT64_TO_HEX << max << ">" << name;
	return tmp_ss_.str();
}

std::string DataFormatter::AddHeatmap(std::string name, uint16_t sizex, uint16_t sizey, int32_t min, int32_t max)
{
	CleanStreamAndIncrementIndex(heatmap_index_);
	tmp_ss_ << "nh" << UINT16_TO_HEX << sizex << UINT16_TO_HEX << sizey << INT32_TO_HEX << min << INT32_TO_HEX << max << ">" << name;
	return tmp_ss_.str();
}

void DataFormatter::CleanStreamAndIncrementIndex(uint16_t &idx)
{
	tmp_ss_.str("");
	tmp_ss_ << UINT16_TO_HEX << idx++;
}

void DataFormatter::ResetIdx()
{
	graph_index_ = 0;
	heatmap_index_ = 0;
}

DataFormatter::~DataFormatter()
{
}
