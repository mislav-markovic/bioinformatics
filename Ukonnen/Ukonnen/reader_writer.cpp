#include "pch.h"
#include "reader_writer.h"



reader_writer::
reader_writer(std::filesystem::path input_file, std::filesystem::path output_file) : input_{std::move(input_file)},
                                                                                     output_{std::move(output_file)}
{
	input_.open(std::move(input_file));
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
