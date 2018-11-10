#ifndef READER_WRITER_H
#define READER_WRITER_H
#include <filesystem>
#include <fstream>

class [[nodiscard]] reader_writer
{
private:
  std::ifstream input_;
  std::ofstream output_;
public:
  reader_writer(std::ifstream input_stream, std::ofstream output_stream);
  reader_writer(const std::filesystem::path& input_file, const std::filesystem::path& output_file);
  void write(const std::string& data);
  void write_flush(const std::string& data);
  void write_ln(const std::string& data);
  [[nodiscard]] std::string read();
};
#endif
