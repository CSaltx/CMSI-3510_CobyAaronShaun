import org.junit.Test;
import static org.junit.Assert.assertTrue;
import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertFalse;
import static org.junit.Assert.assertThrows;

public class BoundedBufferTest extends Thread {

    @Test
    public void testInsert() throws InterruptedException {
        record insertData(Object a) {
        }

        var data = new insertData[] { new insertData(3), new insertData(2),
                new insertData(-100), new insertData('a'), new insertData(32727) };
        BoundedBuffer test = new BoundedBuffer();
        for (var value : data) {
            test.insert(value.a);
            var retrieved = test.retrieve();
            assertEquals(retrieved, value.a);
        }
    }

    @Test
    public void testException() throws InterruptedException {
        BoundedBuffer test = new BoundedBuffer();
        Thread testThread = new Thread(() -> {
            assertThrows(InterruptedException.class, () -> test.retrieve());
        });
        testThread.start();
        Thread.sleep(100);
        assertTrue(testThread.isAlive());

        testThread.interrupt();
        Thread.sleep(100);
        assertFalse(testThread.isAlive());
    }

    @Test
    public void testInsertException() throws InterruptedException {
        BoundedBuffer test = new BoundedBuffer();

        for (var i = 0; i < 20; i++) {
            test.insert('a');
        }

        Thread testThread = new Thread(() -> {
            assertThrows(InterruptedException.class, () -> test.insert('a'));
        });

        testThread.start();
        Thread.sleep(500);
        assertTrue(testThread.isAlive());

        test.retrieve();
        Thread.sleep(500);
        assertFalse(testThread.isAlive());
    }

}
