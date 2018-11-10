#include "pch.h"
#include "reader_writer.h"

reader_writer::reader_writer(std::ifstream input_stream, std::ofstream output_stream) : input_{std::move(input_stream)}, output_{std::move(output_stream)}
{
}

reader_writer::reader_writer(const std::filesystem::path& input_file, const std::filesystem::path& output_file) : input_{input_file}, output_{output_file}
{
}

void reader_writer::write(const std::string& data)
{
  output_ << data;
}

void reader_writer::write_flush(const std::string& data)
{
  output_ << data << std::flush;
}

void reader_writer::write_ln(const std::basic_string<char>& data)
{
  output_ << data << '\n';
}

std::string reader_writer::read()
{
  std::string input{};
  input_ >> input;
  return input;
}
