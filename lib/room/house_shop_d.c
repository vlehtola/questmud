#define SAVE_FILE "/room/houses/house_codes"


int codes;
int costs, sold;

reset(arg) {
  if (arg) return;
  restore_object(SAVE_FILE);
  if (!codes) {
    codes = allocate(20);
    costs = allocate(20);
    sold = allocate(20);
    random_all_codes();
    save_object(SAVE_FILE);
  }
  define_costs();
}

random_all_codes() {
  int i;
  while(i < sizeof(codes)) {
    codes[i] = random_code(i);
    i += 1;
  }
}

random_code(num) {
  string str;
  int i, quality;
  quality = num / 4 + 4;
  str = "";
  while(i < quality) {
    str = str + random(10);
    i += 1;
  }
  return str;
}

set_sold(num, arg) {
  sold[num] = arg;
  save_object(SAVE_FILE);
}

query_sold(num) { return sold[num]; }

set_code(number, code) {
  codes[number] = code;
  save_object(SAVE_FILE);
}


query_code(num) {
  return codes[num];  
}

query_house_costs() {
  return costs;
}


define_costs() {
  int i, num;
  while(i < 10) {
    if (query_sold(i)) { num += 1; }
    i += 1;
  }

  i = 0;
  while(i < 10) {
    costs[i] = 850 * (11+(num/2)+(i));
    if (i == 8 || i == 9) { costs[i] = costs[i] * 2; }
    i += 1;
  }
}
