import React, { useState } from 'react';
import { classNames } from '../../utils';
import './index.css';

export default function ScrollToTop({ f }) {
  const [isVisible, setIsVisible] = useState(false);

  const toggleVisibility = () => {
    const offset = document.documentElement.scrollTop;
    if (offset > 300) {
      setIsVisible(true);
    } else if (offset <= 300) {
      setIsVisible(false);
    }
  };
  window.addEventListener('scroll', toggleVisibility);

  return (
    <div className='fixed bottom-0 right-0 mb-3 mr-3 bg-transparent z-10'>
      <button
        type='button'
        onClick={f}
        className={classNames(
          isVisible ? 'opacity-100' : 'opacity-0 cursor-default',
          'duration-200 transition-all p-3 rounded-full scrollToTop hover:shadow-xl'
        )}
        aria-label='Scroll to top'
        disabled={!isVisible}
      >
        <svg
          xmlns='http://www.w3.org/2000/sv@Kitty6969
          '
          className='h-6 w-6 bg-transparent'
          fill='none'
          viewBox='0 0 24 24'
          stroke='currentColor'
        >
          <path
            strokeLinecap='round'
            strokeLinejoin='round'
            strokeWidth={2}
            d='M5 10l7-7m0 0l7 7m-7-7v18'
          />
        </svg>
      </button>
    </div>
  );
}
