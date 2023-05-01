#ifndef DATAFORMATTER_H
#define DATAFORMATTER_H

#include <Arduino.h>
#include <sstream>
#include <string>
#include <iomanip>


#define UINT16_TO_HEX std::setfill('0') << std::setw(sizeof(uint16_t) * 2) << std::hex
#define INT64_TO_HEX std::setfill('0') << std::setw(sizeof(int64_t) * 2) << std::hex
#define INT32_TO_HEX std::setfill('0') << std::setw(sizeof(int32_t) * 2) << std::hex

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
	uint16_t heatmap_index_;
	std::stringstream ss_;

public:
	DataFormatter() : graph_index_(0), heatmap_index_(0)
	{
		ss_ << "{ ";
	}

	template <class T>
	void AddBarGraph(std::string name, T data)
	{
		ss_ << "\"nb>" << name << "\": " << data << ", ";
	}
	void AddStringLog(color c, std::string contents)
	{
		ss_ << "\"0000s>" << c << "\": " << contents << ", ";
	}
	void AddStringLog(std::string contents)
	{
		ss_ << "\"0000s>\": " << contents << ", ";
	}
	template <class T>
	void AddLineGraph(std::string name, T contents)
	{
		ss_ << "\"" << UINT16_TO_HEX << graph_index_++ << "nl>" << name << "\": " << std::dec << contents << ", ";
	}
	template <class T>
	void AddLineGraph(std::string name, int64_t min, int64_t max, T contents)
	{
		ss_ << "\"" << UINT16_TO_HEX << graph_index_++ << "nl" << INT64_TO_HEX << min << INT64_TO_HEX << max << ">" << name << "\": " << std::dec << contents << ", ";
	}

	void AddHeatmap(std::string name, uint16_t sizex, uint16_t sizey, int32_t min, int32_t max)
	{
		ss_ << UINT16_TO_HEX << heatmap_index_++ << "nh" << UINT16_TO_HEX << sizex << UINT16_TO_HEX << sizey << INT32_TO_HEX << min << INT32_TO_HEX << max << ">" << name;
	}

	void ResetIdx()
	{
		graph_index_ = 0;
		heatmap_index_ = 0;
	}
	String FlushData()
	{
		ss_ << "\"" << UINT16_TO_HEX << graph_index_++ << "nl00000000000000000000000000000000>Milliseconds since start\": " << std::dec << millis() << " }";
		std::string temp = ss_.str();
		ss_.str("");
		ss_ << "{ ";
		ResetIdx();
		return temp.c_str();
	}

	~DataFormatter(){
		
	}
};

#endif /* DATAFORMATTER_H */