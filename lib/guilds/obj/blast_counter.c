int stun, dist;

drop() { return 1; }

id(mixed str) {
  return str == "blast counter";
}

/* value [1,100] */
status add_stun_count(int value) {
  stun += value;
  if(stun > 300 + random(200)) {
    stun = 0;
    return 1;
  }
  return 0;
}

/* value [1,100] */
status add_distract_count(int value) {
  dist += value;
  if(dist > 200 + random(100)) {
    dist = 0;
    return 1;
  }
  return 0;
}
