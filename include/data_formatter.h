#ifndef DATAFORMATTER_H
#define DATAFORMATTER_H

#include <sstream>
#include <string>
#include <iomanip>

#define UINT16_TO_HEX std::setfill('0') << std::setw(sizeof(uint16_t) * 2) << std::hex
#define INT64_TO_HEX std::setfill('0') << std::setw(sizeof(int64_t) * 2) << std::hex

enum color
{
	RED = 'r',
	GREEN = 'g',
	BLUE = 'b'
};

class DataFormatter
{
private:
	uint16_t graph_index_;
	std::stringstream tmp_ss_;

public:
	DataFormatter();
	std::string AddBarGraph(std::string name);
	std::string AddStringLog(color c);
	std::string AddStringLog();
	std::string AddLineGraph(std::string name);
	std::string AddLineGraph(std::string name, int64_t min, int64_t max);
	std::string AddHeatmap(std::string name, uint16_t sizex, uint16_t sizey, int64_t min, int64_t max);
	void CleanStreamAndIncrementIndex();
	void ResetIdx();
	~DataFormatter();
};

#endif /* DATAFORMATTER_H */