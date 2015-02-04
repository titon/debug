<?hh
/**
 * @copyright   2010-2015, The Titon Project
 * @license     http://opensource.org/licenses/bsd-license.php
 * @link        http://titon.io
 */

/**
 * --------------------------------------------------------------
 *  Type Aliases
 * --------------------------------------------------------------
 *
 * Defines type aliases that are used by the debug package.
 */

namespace Titon\Debug {
    use Exception;

    type Error = shape('error' => string, 'level' => string);
    type ErrorCodeMap = Map<int, string>;
    type ExceptionHandler = (function(Exception): void);
    type Metric = shape('running' => bool, 'time.start' => float, 'time.stop' => float, 'time.avg' => float,
        'memory.start' => int, 'memory.stop' => int, 'memory.avg' => int, 'memory.peak' => int);
    type MetricMap = Map<string, Metric>;
}

/**
 * --------------------------------------------------------------
 *  Helper Functions
 * --------------------------------------------------------------
 *
 * Defines global helper functions for common use cases.
 */

namespace {
    use Titon\Debug\Debugger;

    /**
     * @see Titon\Debug\Debugger::inspect()
     */
    function inspect(Exception $e): void {
        echo Debugger::inspect($e);
    }

    /**
     * @see Titon\Debug\Debugger::backtrace()
     */
    function backtrace(?Exception $e = null): void {
        echo Debugger::backtrace($e);
    }

    /**
     * @see Titon\Debug\Debugger::export()
     */
    function export(mixed $var, bool $short = true): void {
        echo Debugger::export($var, $short);
    }

    /**
     * @see Titon\Debug\Debugger::debug()
     */
    function debug(): void {
        echo call_user_func_array(class_meth('Titon\Debug\Debugger', 'debug'), func_get_args());
    }

    /**
     * @see Titon\Debug\Debugger::dump()
     */
    function dump(): void {
        echo call_user_func_array(class_meth('Titon\Debug\Debugger', 'dump'), func_get_args());
    }
}
