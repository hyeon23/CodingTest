std::map<std::string, double> pitcher_list;

pitcher_list.insert(std::pair<std::string, double>("박세웅", 123.4));

pitcher_list.insert(std::makepair("박세웅", 123.4));

pitcher_list["박세웅"] = 123.4;