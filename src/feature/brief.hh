//File: brief.hh
//Author: Yuxin Wu <ppwwyyxx@gmail.com>

#pragma once
#include <vector>
#include <utility>
#include "feature.hh"

// BRIEF: Binary Robust Independent Elementary Features

namespace feature {

struct BriefPattern {
	typedef std::pair<int, int> PII;
	int s;	// size
	std::vector<PII> pattern;
};


// Brief algorithm implementation
class BRIEF {
	public:
		BRIEF(const Mat32f& img, const std::vector<SSPoint>&,
				const BriefPattern&);

		std::vector<Descriptor> get_descriptor() const;

		// s: size of patch. n: number of pair
		static BriefPattern gen_brief_pattern(int s, int n);

	protected:
		const Mat32f& img;
		const std::vector<SSPoint>& points;
		const BriefPattern& pattern;

		Descriptor calc_descriptor(const SSPoint&) const;
};

}
