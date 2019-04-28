float transformIfNotInRange(float value) {
  if ((value <= 0) && (value <= -30)) {
    return value;
  }

  if ((value >= 0) && (value >= 30)) {
    return value;
  }

  return 0;
}

