/*
 * MemoryMonitor.cpp
 *
 *  Created on: 15.03.2020 ã.
 *      Author: xxx
 */

#include <iostream>
#include "MemoryMonitor.h"
#include "Structs.h"
#include "Defines.h"

#define SIZE_IN_BYTES 4

MemoryMonitor::MemoryMonitor(){};
MemoryMonitor::~MemoryMonitor(){};

void MemoryMonitor::pushNode(const int nodeSize)
{
	struct MemoryNode newMemNode;
	newMemNode.data = new int[nodeSize];
	newMemNode.size = nodeSize;
	(this->_nodes).push_back(newMemNode);
	std::cout << "Pushed node with memory occupation: "
			<< (nodeSize * SIZE_IN_BYTES) << std::endl;
}

void MemoryMonitor::popNode()
{
	if((this->_nodes).size() > 0)
	{
		MemoryNode lastMN = (this->_nodes).back();
		std::cout << "Popped node with memory occupation: "
				<< (lastMN.size) * SIZE_IN_BYTES << std::endl;
		delete(lastMN.data);
		(this->_nodes).pop_back();
	}
	else
	{

		std::cout << "No nodes to pop" << std::endl;
	}
}

void MemoryMonitor::printMemoryOccupation(const int numberOfNodes)
{
	size_t memOcupation = 0;

	if((unsigned int)numberOfNodes >= (this->_nodes).size())
	{
		for(struct MemoryNode mn : (this->_nodes))
		{
			memOcupation += mn.size;
		}
		std::cout << "Memory occupation for first " << (this->_nodes).size()
				<< " nodes is: " << memOcupation * SIZE_IN_BYTES << std::endl;

	}
	else
	{
		for(int i = 0; i < numberOfNodes; i++)
		{
			memOcupation += (this->_nodes)[i].size;
		}
			std::cout << "Memory occupation for first " << numberOfNodes
						<< " nodes is: " << memOcupation * SIZE_IN_BYTES << std::endl;
	}

}

MemoryNode MemoryMonitor::getLastNode() const
{
	return (this->_nodes).back();
}


