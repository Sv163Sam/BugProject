#include "stdafx.h"
#include "save.h"

std::map<CString, int> count_occurrences(const std::vector<CString>& parts)
{
	std::map<CString, int> counts;
	for (const auto& part : parts)	
		++counts[part];

	return counts; 
}

void save_to_file(std::filesystem::path path, std::vector<CString> const& parts)
{
	if (parts.empty())
		return; 

	std::map<CString, int> occurrence_counts = count_occurrences(parts);

	std::vector<std::pair<CString, int>> sorted_counts(occurrence_counts.begin(), occurrence_counts.end());
	
	std::sort(sorted_counts.begin(), sorted_counts.end(), [](const auto& a, const auto& b){
		return a.second > b.second;});

	std::ofstream out(path, std::ios::out | std::ios::binary);

	if (out.fail())
		return;

	for (const auto& pair : sorted_counts)
	{
		out.put(0xFF);
		out.put(0xFE);

		for (const auto& sym : (std::wstring)pair.first)
		{
			out.put(static_cast<char>(sym & 0xFF));
			out.put(static_cast<char>((sym >> 8) & 0xFF));
		}

		out.write(" ", sizeof(" "));

		for (const auto& sym : std::to_wstring(pair.second))
		{
			out.put(static_cast<char>(sym & 0xFF));
			out.put(static_cast<char>((sym >> 8) & 0xFF));
		}
		
		out.write("\n", sizeof("\n"));
	}
	out.close();
	return;
}  
