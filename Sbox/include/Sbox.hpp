
#ifndef SBOX_HPP_
#define SBOX_HPP_

class Sbox
{
	std::vector<std::vector<int8_t>> m_resLinearTable;
	std::vector<std::vector<int8_t>> m_resDiffTable;
	uint8_t m_soutput[];

	Sbox(uint8_t soutput[],size);
	
	~Sbox();
	
	std::vector<std::vector<int8_t>> calculatLinearTable(void);
	
	std::vector<std::vector<int8_t>> calculateDiffTable(void);
}

#endif // SBOX_HPP_
