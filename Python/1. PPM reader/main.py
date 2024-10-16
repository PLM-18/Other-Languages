def read_ppm_p6(filename):
    with open(filename, 'rb') as f:
        # Read the header
        header = f.readline().strip()  # Magic number P6
        assert header == b'P6'
        
        # Read the dimensions and max color value
        dimensions = f.readline().strip()
        width, height = map(int, dimensions.split())
        max_value = int(f.readline().strip())  # Should be 255
        
        # Read the binary pixel data
        pixel_data = f.read(width * height * 3)  # Each pixel has 3 bytes (RGB)
        
    return width, height, pixel_data

width, height, data = read_ppm_p6('tester.ppm')
