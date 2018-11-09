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
  explicit reader_writer(std::filesystem::path input_file, std::filesystem::path output_file);

  void write(const std::string& data);
  void write_flush(const std::string& data);
  void write_ln(const std::string& data);

  [[nodiscard]]
  std::string read();
};


#endif
