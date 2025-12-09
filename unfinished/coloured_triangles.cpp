std::string triangle(std::string row_str) {
  std::string row = row_str;
  std::string new_row;
  enum Color {
    GB, BG, RR, RG, GR, BB, BR, RB, GG
  };
  for (size_t i {1}; i < row.size(); ++i) {
    for (size_t j {1}; j < row.size(); ++i) {
      Color cur {GB};
      switch (cur) {
        case GB:
        case BG:
        case RR: 
          new_row.push_back('R');
          break;

        case RG:
        case GR:
        case BB:
          new_row.push_back('B');
          break;

        case BR:
        case RB:
        case GG:
          new_row.push_back('G');
          break;
      }
    }
    row = new_row;
    new_row.clear();
  }
  return row;
}
