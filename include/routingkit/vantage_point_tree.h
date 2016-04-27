#ifndef ROUTING_KIT_VANTAGE_POINT_TREE_H
#define ROUTING_KIT_VANTAGE_POINT_TREE_H

#include <routingkit/constants.h>
#include <vector>
#include <algorithm>

namespace RoutingKit{

class VantagePointTree{
public:
	VantagePointTree(){};

	VantagePointTree(const std::vector<float>&latitude, const std::vector<float>&longitude);

	unsigned point_count() const {
		return point_position.size();
	}

	struct NearestNeighborhoodQueryResult{
		unsigned id;
		float distance;
		
	};

	NearestNeighborhoodQueryResult find_nearest_neighbor_within_radius(float query_latitude, float query_longitude, float query_radius)const;


// private:
	struct PointPosition{
		float latitude;
		float longitude;
	};

	std::vector<PointPosition>point_position;
	std::vector<unsigned>point_id;

};

} // RoutingKit

#endif 
