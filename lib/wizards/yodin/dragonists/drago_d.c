mapping taken;

void reset(status x) {
  if(!taken) taken = ([ ]);
}

status query_taken(string str) {
  if(taken[str]) return 1;
}

void set_taken(string str) {
  if(taken[str]) return;
  taken += ([ str:1, ]);
}

void set_back(string str) {
  if(!taken[str]) return;
  taken = m_delete(taken,str);
}
