/**
 * This class contains class (static) methods that will help you test the
 * Picture class methods. Uncomment the methods and the code in the main to
 * test.
 * 
 * @author Barbara Ericson
 */
public class PictureTester {
	/** Method to test zeroBlue */
	public static void testZeroBlue() {
		Picture beach = new Picture("beach.jpg");
		beach.explore();
		beach.zeroBlue();
		beach.explore();
	}

	/** Method to test mirrorVertical */
	public static void testMirrorVertical() {
		Picture caterpillar = new Picture("caterpillar.jpg");
		caterpillar.explore();
		caterpillar.mirrorVertical();
		caterpillar.explore();
	}

	/** Method to test mirrorTemple */
	public static void testMirrorTemple() {
		Picture temple = new Picture("temple.jpg");
		temple.explore();
		temple.mirrorTemple();
		temple.explore();
	}

	/** Method to test the collage method */
	public static void testCollage() {
		Picture canvas = new Picture("640x480.jpg");
		canvas.createCollage();
		canvas.explore();
	}

	/** Method to test edgeDetection */
	public static void testEdgeDetection() {
		Picture swan = new Picture("swan.jpg");
		swan.edgeDetection(10);
		swan.explore();
	}

	public static void negate() {
		Picture potato = new Picture("potato.png");
		Pixel[][] pixels = potato.getPixels2D();
		for (Pixel[] rowArray : pixels) {
			for (Pixel pixelObj : rowArray) {
				pixelObj.setRed(255 - pixelObj.getRed());
				pixelObj.setGreen(255 - pixelObj.getGreen());
				pixelObj.setBlue(255 - pixelObj.getBlue());
			}
		}
		potato.explore();
	}

	public static void grayscale() {
		Picture potato = new Picture("potato.png");
		Pixel[][] pixels = potato.getPixels2D();
		for (Pixel[] rowArray : pixels) {
			for (Pixel pixelObj : rowArray) {
				int average = (pixelObj.getRed() + pixelObj.getGreen() + pixelObj.getBlue()) / 3;
				pixelObj.setRed(average);
				pixelObj.setGreen(average);
				pixelObj.setBlue(average);
			}
		}
		potato.explore();
	}

	public static void fixUnderwater() {
		Picture water = new Picture("water.jpg");
		Pixel[][] pixels = water.getPixels2D();
		for (Pixel[] rowArray : pixels) {
			for (Pixel pixelObj : rowArray) {
				pixelObj.setRed(pixelObj.getRed() * 3);
			}
		}
		water.explore();
	}
	
	public static void mirrorHorizontal() {
		Picture potato = new Picture("potato.png");
		Pixel[][] pixels = potato.getPixels2D();
		for (int i = 0; i < pixels.length / 2; ++i) {
			for (int j = 0; j < pixels[0].length; ++j) {
				pixels[pixels.length - i - 1][j].setColor(pixels[i][j].getColor());
			}
		}
		potato.explore();
	}
	
	public static void mirrorDiagonal() {
		Picture potato = new Picture("potato.png");
		Pixel[][] pixels = potato.getPixels2D();
		for(int i = 0; i < pixels.length; ++i) {
			for(int j = 0; j < i; ++j) {
				pixels[j][i].setColor(pixels[i][j].getColor());
			}
		}
		potato.explore();
	}
	
	public static void mirrorGull() {
		Picture seagull = new Picture("seagull.jpg");
		Pixel[][] pixels = seagull.getPixels2D();
		int mirrorPoint = 231;
		Pixel leftPixel = null;
		Pixel rightPixel = null;
		int count = 0;
		for(int i = 100; i < 352; ++i) {
			for(int j = 229; j < 348; ++j) {
				leftPixel = pixels[i][j];
				rightPixel = pixels[i][mirrorPoint-j+mirrorPoint];
				rightPixel.setColor(leftPixel.getColor());
			}
		}
		seagull.explore();
	}

	/**
	 * Main method for testing. Every class can have a main method in Java
	 */
	public static void main(String[] args) {
		// uncomment a call here to run a test
		// and comment out the ones you don't want
		// to run
		mirrorGull();
//		mirrorDiagonal();
//		mirrorHorizontal();
//		fixUnderwater();
//		grayscale();
//		negate();
//    testZeroBlue();
		// testKeepOnlyBlue();
		// testKeepOnlyRed();
		// testKeepOnlyGreen();
		// testNegate();
		// testGrayscale();
		// testFixUnderwater();
		// testMirrorVertical();
		// testMirrorTemple();
		// testMirrorArms();
		// testMirrorGull();
		// testMirrorDiagonal();
		// testCollage();
		// testCopy();
		// testEdgeDetection();
		// testEdgeDetection2();
		// testChromakey();
		// testEncodeAndDecode();
		// testGetCountRedOverValue(250);
		// testSetRedToHalfValueInTopHalf();
		// testClearBlueOverValue(200);
		// testGetAverageForColumn(0);
	}
}