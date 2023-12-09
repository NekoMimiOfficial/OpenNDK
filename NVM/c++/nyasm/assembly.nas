:start
{
  LDA(1);
  LDX(1);
  SYS();
  JMP(end)
}

:end
{
  LDA(0);
  RET();
}
