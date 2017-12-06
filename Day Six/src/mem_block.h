/*
 * mem_block.h
 *
 *  Created on: Dec 5, 2017
 *      Author: hayden
 */

#ifndef SRC_MEM_BLOCK_H_
#define SRC_MEM_BLOCK_H_

#include <vector>

class mem_block
{
public:
	mem_block(std::vector<int> mem_map);
	~mem_block( void );

	int 	get_redist_cand( void );
	void  	redist( int redist_pos );
	int  	check_dupe( void );
	int 	get_num_redist();

protected:
	std::vector<int> 			* 	_mem_map;
	std::vector<std::vector<int> >	_previous_values;
	int								_num_redist;
};



#endif /* SRC_MEM_BLOCK_H_ */
