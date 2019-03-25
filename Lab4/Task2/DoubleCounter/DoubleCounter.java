class DoubleCounter {
  public static void main(String[] args) {
    double doublePrecisionNum = 1.0000000;
    double doublePrecisionSucc = 1.0000001;
    long amountOfDoublesBetween = 0;

    while (doublePrecisionNum <= doublePrecisionSucc) {
      amountOfDoublesBetween++;
      doublePrecisionNum = Math.nextUp(doublePrecisionNum);
    }

    System.out.printf("Amount of doubles between 1.0000000 and 1.0000001 is %d.\n", amountOfDoublesBetween);
  }
}
