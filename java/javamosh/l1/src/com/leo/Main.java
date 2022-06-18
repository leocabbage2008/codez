package com.leo;

import java.text.NumberFormat;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        System.out.print("Principal: ");
        Scanner principal = new Scanner(System.in);
        float pri = principal.nextFloat();

        System.out.print("Annual Interest Rate: ");
        Scanner interest = new Scanner(System.in);
        float apr = interest.nextFloat()/1200;

        System.out.print("Period (Years): ");
        Scanner period = new Scanner(System.in);
        float p = period.nextFloat()*12;

        String mortgage = NumberFormat.getCurrencyInstance().format(pri*(apr*Math.pow(1+apr,p))/(Math.pow(1+apr,p)-1));

        System.out.print("Mortgage: ");
        System.out.println(mortgage);
    }
}