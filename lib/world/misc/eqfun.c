query_material(material) {
  if(material == 0) { return "wooden"; }
  if(material == 1) { return "zink"; }
  if(material == 2) { return "aluminium"; }
  if(material == 3) { return "copper"; }
  if(material == 4) { return "bronze"; }
  if(material == 5) { return "cast iron"; }
  if(material == 6) { return "iron"; }
  if(material == 7) { return "steel"; }
  if(material == 8) { return "titanium"; }
  if(material == 9) { return "adamantium"; }
  if(material == 10) { return "mithril"; }
}
query_class(class) {
  string str;
  if(class < 3) { str = "crude"; }
  if(class > 2) { str = ""; }
  if(class > 5) { str = "fine"; }
  if(class > 8) { str = "very fine"; }
  return str;
}

