short() { return "A recommendation scroll"; }

long() {
  write(
"This scroll is clearly somekind of a recommendation, mentioning something\n"+
"about the illusionists and the electricity school. It has the signing of\n"+
"Sorian on it.\n");
}

get() { return 1; }

query_recommendation() { return 1; }

id(str) {
  if (str == "scroll" || str == "recommendation") return 1;
}
