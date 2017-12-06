/*
 * mem_block.cpp
 *
 *  Created on: Dec 5, 2017
 *      Author: hayden
 */

#include "mem_block.h"

#include <iterator>
#include <algorithm>

mem_block::mem_block(std::vector<int> mem_map)
{
	_num_redist = 0;
	_mem_map = new std::vector<int>(mem_map);
	_previous_values.push_back(*_mem_map);
}

mem_block::~mem_block( void )
{
	_mem_map->clear();
	delete _mem_map;
}

int mem_block::get_redist_cand( void )
{
	std::vector<int>::iterator iter;
	int position = 0;

	iter = max_element(_mem_map->begin(), _mem_map->end());
	position = std::distance(_mem_map->begin(), iter);

	return position;
}

void mem_block::redist( int redist_pos )
{
	int val_redist = 0;

	val_redist = _mem_map->at(redist_pos);
	_mem_map->at(redist_pos) = 0;
	redist_pos++;

	while(val_redist > 0)
	{
		_mem_map->at(redist_pos%_mem_map->size())++;
		redist_pos++;
		val_redist--;
	}
	_num_redist ++;
	_previous_values.push_back(*_mem_map);

}

int mem_block::check_dupe( void )
{
	int dupe_count = 0;
	for(int i = 0; i < _previous_values.size(); i++)
	{
		if(_previous_values.at(i) == *_mem_map)
		{
			dupe_count++;
		}
	}
	return dupe_count;
}

int mem_block::get_num_redist( void )
{
	return _num_redist;
}



