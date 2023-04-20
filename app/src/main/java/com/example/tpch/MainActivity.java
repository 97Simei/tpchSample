package com.example.tpch;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {
    // Used to load the 'tpch3' library on application startup.
    static {
        System.loadLibrary("duckDBHelper");
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        System.out.print(stringFromJNI());
    }
    public native String stringFromJNI();
}