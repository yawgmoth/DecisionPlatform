      FUNCTION getrand(y, fp1, fp2, sf)
      INTEGER getrand
      INTEGER y(4)
      INTEGER fp1
      INTEGER fp2
      INTEGER sf
      INTEGER num
      INTEGER convresult(8)
      INTEGER h(4)
      INTEGER r
     ! highpass filter
      h(1) = -sf
      h(2) = sf
      h(3) = -sf
      h(4) = sf
      r = callfunc(fp1, fp2)
      i = 1
    ! convolution with filter impulse response
10    y(i) = y(i+1)
      i = i +1
      if (i-4) 10,20,30
20    y(4) = r
      i = 1
30    k = 0
      j = 1
35    iy = i - j
      if (iy.lt.0) then
      ii = 0
      else
      if (iy.lt.4) then
      ii = y(iy+1)*h(j)
      else
      ii = 0
      end if
      end if
      k = k + ii
      j = j + 1
      if (j-5) 35,45,40
45    convresult(i) = k
      i = i +1
      if (i-9) 30,40,50
40    i = 1
    ! normalize values, return new value
50    if (convresult(i).lt.1) then
      y(i) = 1
      else
      y(i) = 0
      end if
      num = y(i)
      i = i + 1
      if (i-5) 50,60,10
60    getrand = num
      END FUNCTION getrand

 