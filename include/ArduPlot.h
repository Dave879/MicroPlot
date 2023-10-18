#ifndef ARDUPLOT_H
#define ARDUPLOT_H

#if ARDUPLOT_DEBUG == true

/**
 * If you use these macros, the serial printing of the packet header
 * is more optimized (Serial.print() gets called only once instead of
 * multiple times), but the syntax is slightly less friendly
*/
#define ARDUPLOT_LINE_GRAPH(title, value) _ArduPlot_MM::LineGraph("{\"0&n&l&" title "\":", value)
#define ARDUPLOT_SHARED_LINE_GRAPH(title, value, id) _ArduPlot_MM::LineGraph("{\"" id "&n&l&" title "\":", value)

#define ARDUPLOT_HEATMAP_MIN_MAX(title, sizex, sizey, min, max, arr, size) _ArduPlot_MM::Heatmap("{\"0&n&h&" title "&" sizey "&" sizex "&" min "&" max "\":[", arr, size)
#define ARDUPLOT_HEATMAP(title, sizex, sizey, arr, size) _ArduPlot_MM::Heatmap("{\"0&n&h&" title "&" sizey "&" sizex "\":[", arr, size)

namespace ArduPlot
{
	/**
	 * @param title The name of the graph, must be unique
	 * @param value The actual value that you want displayed in the graph
	 */
	void LineGraph(String title, double value)
	{
		Serial.print("{\"0&n&l&");
		Serial.print(title);
		Serial.print("\":");
		Serial.print(value);
		Serial.print("}");
	}

	/**
	 * @param title The name of the graph, must be unique
	 * @param value The actual value that you want displayed in the graph
	 * @param id Graphs with the same id get merged in the same line graph
	 */
	void LineGraph(String title, double value, unsigned int id)
	{
		Serial.print("{\"");
		Serial.print(id);
		Serial.print("&n&l&");
		Serial.print(title);
		Serial.print("\":");
		Serial.print(value);
		Serial.print("}");
	}

	/**
	 * @param title The name of the graph, must be unique
	 * @param sizex The number of "squares" in the X direction (horizontal)
	 * @param sizey The number of "squares" in the Y direction (vertical)
	 * @param min The minimum value (used for heatmap coloring)
	 * @param max The maximum value (used for heatmap coloring)
	 * @param arr The array itself
	 * @param size The size of the array
	 */
	template <typename T>
	void Heatmap(String title, unsigned int sizex, unsigned int sizey, double min, double max, T arr, unsigned int size)
	{
		Serial.print("{\"0&n&h&");
		Serial.print(title);
		Serial.print("&");
		Serial.print(sizey);
		Serial.print("&");
		Serial.print(sizex);
		Serial.print("&");
		Serial.print(min);
		Serial.print("&");
		Serial.print(max);
		Serial.print("\":[");
		for (unsigned int i = 0; i < size; i++)
		{
			Serial.print(arr[i]);
			if (i != size - 1)
			{
				Serial.print(",");
			}
		}
		Serial.print("]}");
	}

	/**
	 * @param title The name of the graph, must be unique
	 * @param sizex The number of "squares" in the X direction (horizontal)
	 * @param sizey The number of "squares" in the Y direction (vertical)
	 * @param arr The array itself
	 * @param size The size of the array
	 */
	template <typename T>
	void Heatmap(String title, unsigned int sizex, unsigned int sizey, T arr, unsigned int size)
	{
		Serial.print("{\"0&n&h&");
		Serial.print(title);
		Serial.print("&");
		Serial.print(sizey);
		Serial.print("&");
		Serial.print(sizex);
		Serial.print("\":[");
		for (unsigned int i = 0; i < size; i++)
		{
			Serial.print(arr[i]);
			if (i != size - 1)
			{
				Serial.print(",");
			}
		}
		Serial.print("]}");
	}
}

/**
 * For ArduPlot Macro Madness
 * !!!DO NOT USE STANDALONE!!!
*/
namespace _ArduPlot_MM
{
	/**
	 * !!!DO NOT USE STANDALONE, USE WITH APPROPRIATE MACRO!!!
	 * @param prefix The prefix, containing the "static" graph information (name, min, max)
	 * @param value The actual value that you want displayed in the graph
	 */
	void LineGraph(String prefix, double value)
	{
		Serial.print(prefix);
		Serial.print(value);
		Serial.print("}");
	}

	/**
	 * !!!DO NOT USE STANDALONE, USE WITH APPROPRIATE MACRO!!!
	 * @param prefix The prefix, containing the "static" graph information (name, min, max)
	 * @param arr The array itself
	 * @param size The size of the array
	 */
	template <typename T>
	void Heatmap(String prefix, T arr, unsigned int size)
	{
		Serial.print(prefix);
		for (unsigned int i = 0; i < size; i++)
		{
			Serial.print(arr[i]);
			if (i != size - 1)
			{
				Serial.print(",");
			}
		}
		Serial.print("]}");
	}
}

#else

#define ARDUPLOT_LINE_GRAPH(title, value)
#define ARDUPLOT_SHARED_LINE_GRAPH(title, value, id)

#define ARDUPLOT_HEATMAP_MIN_MAX(title, sizex, sizey, min, max, arr, size)
#define ARDUPLOT_HEATMAP(title, sizex, sizey, arr, size) 

namespace ArduPlot
{
	void LineGraph(String title, double value){}

	void LineGraph(String title, double value, unsigned int id){}

	template <typename T>
	void Heatmap(String title, unsigned int sizex, unsigned int sizey, double min, double max, T arr, unsigned int size){}

	template <typename T>
	void Heatmap(String title, unsigned int sizex, unsigned int sizey, T arr, unsigned int size){}
}

#endif

#endif /* ARDUPLOT_H */