#include "data_formatter.h"

DataFormatter::DataFormatter() : graph_index_(0)
{
}

std::string DataFormatter::AddBarGraph(std::string name)
{
	CleanStreamAndIncrementIndex();
	tmp_ss_ << "nb>" << name;
	return tmp_ss_.str();
}

std::string DataFormatter::AddStringLog(color c)
{
	CleanStreamAndIncrementIndex();
	tmp_ss_ << "s>" << c;
	return tmp_ss_.str();
}

std::string DataFormatter::AddStringLog()
{
	CleanStreamAndIncrementIndex();
	tmp_ss_ << "s>";
	return tmp_ss_.str();
}

std::string DataFormatter::AddLineGraph(std::string name)
{
	CleanStreamAndIncrementIndex();
	tmp_ss_ << "nl>" << name;
	return tmp_ss_.str();
}

std::string DataFormatter::AddLineGraph(std::string name, int64_t min, int64_t max)
{
	CleanStreamAndIncrementIndex();
	tmp_ss_ << "nl" << INT64_TO_HEX << min << INT64_TO_HEX << max << ">" << name;
	return tmp_ss_.str();
}

std::string DataFormatter::AddHeatmap(std::string name, uint16_t sizex, uint16_t sizey, int64_t min, int64_t max)
{
	CleanStreamAndIncrementIndex();
	tmp_ss_ << "nh" << UINT16_TO_HEX << sizex << UINT16_TO_HEX << sizey << INT64_TO_HEX << min << INT64_TO_HEX << max << ">" << name;
	return tmp_ss_.str();
}

void DataFormatter::CleanStreamAndIncrementIndex()
{
	tmp_ss_.str("");
	tmp_ss_ << UINT16_TO_HEX << graph_index_++;
}

void DataFormatter::ResetIdx()
{
	graph_index_ = 0;
}

DataFormatter::~DataFormatter()
{
}
