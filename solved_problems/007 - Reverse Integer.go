import "math"

func reverse(x int) int {
    var negative bool = (x < 0);
    var n, rn int64 = int64(math.Abs(float64(x))), 0;
    
    for n > 0 {
        rn = rn * 10 + n % 10;
        n = n / 10;
    }
    
    if negative {
        rn = -rn;
    }
    
    if rn > math.MaxInt32 || rn < math.MinInt32  {
        return 0;
    }
    
    return int(rn);
}