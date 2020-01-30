cmd_uptime() 
{
  object ob, *list;
  float cpu;
  string time;
  list = users();
  ob = find_object("/obj/timer");
  time = ob->query_time(); 
  cpu = to_float(rusage()[1]) / to_float(rusage()[0]);
  cpu = to_float(force_string_length(to_string(cpu), 4));

  write("Uptime: "+time+", "+sizeof(list)+" users. "+query_load_average()+". CPU "+cpu+"%\n");
  return 1;
}

