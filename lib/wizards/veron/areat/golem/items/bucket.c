reset(arg) {
  if(arg) return;
}

short() {
  return "A bucket full of oily water";
}

id(str) {
  return str == "bucket";
}

realid(str) {
  return str == "real";
}

long() {
  write("A bucket made of sheet metal. It is full of water. There's a layer of\n" + 
        "oil floating on the surface. A torch has probably been put out in it.\n");
        
}

get() {
  return 1;
}

query_weight() {

  return 1;
}